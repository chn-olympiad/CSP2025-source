#include<bits/stdc++.h>
using namespace std;
int t,n;
struct people{
    int a,b,c,max1;
}a[100010];
bool cmp(people a,people b){
    return a.max1 > b.max1;
}
int s[100100][4];
int a1,b1,c1,x,ans,k;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        ans=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i].a >> a[i].b >> a[i].c;
            a[i].max1 = max(a[i].a,a[i].b);
            a[i].max1 = max(a[i].c,a[i].max1);
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            s[i][1] = a[i].a;
            s[i][2] = a[i].b;
            s[i][3] = a[i].c;
            //cout << a[i].a << a[i].b << a[i].c << endl;
        }
        for(int i=1;i<n;i+=2){
        	x=0;
            for(int j=1;j<=3;j++){
            	a1=0;b1=0;c1=0;
            	
            //	cout << k;
                if( j == 1 )  a1++;
                if( j == 2 )  b1++;
                if( j == 3 )  c1++;
                for(int k=1;k<=3;k++){
                    if( k == 1 )  a1++;
                    if( k == 2 )  b1++;
                    if( k == 3 )  c1++;
                    if( a1 <= n/2 && b1 <= n/2 && c1 <= n/2 ){
                        x = max(x,s[i][j]+s[i+1][k]);
                        //cout << s[i][j] << " " << s[i+1][k] <<  endl;
                    }
                }
            }
            ans+=x;
        	//cout << x << endl;
        }
        cout << ans << endl;
    }
    

	fclose(stdin);
	fclose(stdout);
    return 0;
}

