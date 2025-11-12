#include<bits/stdc++.h>
using namespace std;
int a[1000000];
bool check(int a,int b,int c){
	if(a+b+c<=c*2) return false;
	return true;
}
bool check2(int a,int b,int c,int d){
	if(a+b+c+d<=d*2) return false;
	return true;
}
bool check3(int a,int b,int c,int d,int e){
	if(a+b+c+d+e<=e*2) return false;
	return true;
}
int ans;
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n-2;i++){
		for(int j = i+1;j<=n-1;j++){
			for(int k = j+1;k<=n;k++){
				if(check(a[i],a[j],a[k])) ans++;
			}
		}
	}
	for(int i =1;i<=n-3;i++){
		for(int j = i+1;j<=n-2;j++){
			for(int k = j+1;k<=n-1;k++){
				for(int l = k+1;l<=n;l++){
					if(check2(a[i],a[j],a[l],a[k])) ans++;
				}
			}
		}
	}
	for(int v = 1;v<=n-4;v++){
		for(int i =v+1;i<=n-3;i++){
			for(int j = i+1;j<=n-2;j++){
				for(int k = j+1;k<=n-1;k++){
					for(int l = k+1;l<=n;l++){
						if(check3(a[v],a[i],a[j],a[l],a[k])) ans++;
				}
			}
		}
	}
}
	cout<<ans;
	return 0;
} 
