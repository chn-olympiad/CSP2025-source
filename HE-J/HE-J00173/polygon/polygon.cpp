#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	int ans=0;
	int n,tot,maxx;
	int a[5100];
	cin>>n;      //输入 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){      //枚举选择小棒的数量 
			tot=0;
			maxx=0;
			for(int j=1;j<=i;j++){
				for(int k=1;k<=i;k++){      //小棒总长度 
					tot=tot+a[k];
					if(a[k]>maxx){      //最长小棒 
					maxx=a[k];	
					}
				}
			if(tot>maxx*2&&i>=3){      //是否能拼成多边形
				ans++;
			}
			}
		}	
	cout<<ans;
	fclose("seat.cpp")
	return 0;
}
