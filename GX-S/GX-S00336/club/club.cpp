#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		
		int n,a[100010][5],num[100010],a1=0,b1=0,c1=0,sum=0,m[100010],b[100010],num3=1,num4=1;
		cin>>n;
        for(int i=1;i<=n;i++){
		    num[i]=0;
	    }
        for(int i=1;i<=n;i++){
		    b[i]=20010;
	    }
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=3;j++){
		        cin>>a[i][j];
		        if(a[i][j]>num[i]) num[i]=a[i][j];
		    }
		}
        for(int i=1;i<=n;i++){
		    for(int j=1;j<=3;j++){
		        if(a[i][j]==num[i]){
					if(j==1){
						a1++;
						m[i]=j;
					}
					if(j==2){
						b1++;
						m[i]=j;
					}
					if(j==3){
						c1++;
						m[i]=j;
					}
				}
		    }
		}
		if(a1<=n/2&&b1<=n/2&&c1<=n/2){
			for(int i=1;i<=n;i++){
				sum+=num[i];
			}
		}else while(a1>n/2||b1>n/2||c1>n/2){
		    num3=1;
		    num4=1;
			if(a1>n/2&&b1<n/2&&c1<n/2){
				for(int i=1;i<=n;i++){
					if(m[i]==1){
						b[num3]=a[i][1];
						num3++;
					}
				}
				sort(b+1,b+num3+1);
				for(int i=1;i<=n;i++){
					if(a[i][1]==b[num4]){
						if(a[i][2]>a[i][3]){
							num[i]=a[i][2];
							a1--;
							b1++;
						}else{
							num[i]=a[i][3];
							a1--;
							c1++;
						}
						num4++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			sum+=num[i];
			}
	    cout<<sum<<endl;
	}
	return 0;
}

