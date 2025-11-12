#include<bits/stdc++.h>
using namespace std;
int a[10000002];
int main(){
	freopen("amploy.in","r",stdin);
	freopen("amploy.out","w",stdout);
	int n;
	int m;
	cin>>n;
	cin>>m;
	int s;
	cin>>s;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	int qwedsa=0;
	int ans;
	int zhangjunhaooo=0;
	for(int i = zhangjunhaooo;i<=n;i++){
		for(int j = zhangjunhaooo;j<=n;i++){
			if(s%a[i]<=s){
				qwedsa++;
				ans=qwedsa;
			}
			for(int k=zhangjunhaooo;k<=n;k++){
				break;
			}
		}	
	}
	while(s--){
		for(int i = zhangjunhaooo;i<=n;i++){
			for(int j = zhangjunhaooo;j<=n;i++){
				if(s%a[i]<=s){
					qwedsa++;
					ans=qwedsa;
				}
				for(int k=zhangjunhaooo;k<=n;k++){
					break;
				}
			}	
		}
	}
	cout<<ans<<endl;
	return 0;
}