
#include<bits/stdc++.h>
using namespace std;
const int M=100010;
int t,n,a1,b1,c1,mx=0,ans=0;
int a[M][5],f[M];
bool pd(int x[],int y[]){
        if(x[0]>=y[0]) return false;
        else return true;
}
bool cmp(int x[],int y[]){
    if(x[4]!=y[4])
        if(x[4]<y[4]) return true;
        else return false;
return pd(x,y);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
		for(int w=1;w<=t;w++){
		cin>>n;a1=0,b1=0,c1=0,mx=0,ans=0;
			for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
            int ma=max(a[i][1],max(a[i][2],a[i][3]));
            a[i][0]=ma;
                if(ma==a[i][1]) f[i]=1,a1++;
                if(ma==a[i][2]) f[i]=2,b1++;
                if(ma==a[i][3]) f[i]=3,c1++;
            a[i][4]=f[i];
            ans+=a[i][f[i]];
			}
        mx=max(a1,max(b1,c1));
            if(mx<=n/2) cout<<ans<<endl;
            else{
            ans=0;
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        if(cmp(a[i],a[j])){
                        //cout<<i<<" "<<j<<endl;
                        swap(a[i],a[j]);
                        }
                /*
                for(int i=1;i<=n;i++)
                cout<<a[i][0]<<" ";
                */
                if(mx==a1)
                    for(int i=a1;i>a1-(mx-n/2);i--){
                    a1--;
                        if(a[i][2]>a[i][3]) b1++,a[i][4]=2,a[i][0]=a[i][2];
                        else c1++,a[i][4]=3,a[i][0]=a[i][3];
                    }
                else if(mx==b1){
                int N=a1+b1;
                    for(int i=N;i>N-(mx-n/2);i--){
                    b1--;
                        if(a[i][1]>a[i][3]) a1++,a[i][4]=1,a[i][0]=a[i][1];
                        else c1++,a[i][4]=3,a[i][0]=a[i][3];
                    }
                }
                else if(mx==c1){
                int N=a1+b1+c1;
                    for(int i=N;i>N-(mx-n/2);i--){
                    c1--;
                        if(a[i][1]>a[i][2]) a1++,a[i][4]=1,a[i][0]=a[i][1];
                        else b1++,a[i][4]=2,a[i][0]=a[i][2];
                    }
                }
                for(int i=1;i<=n;i++)
                    ans+=a[i][0];
                cout<<ans<<endl;
                }
            }
    fclose(stdin);fclose(stdout);
	return 0;
}