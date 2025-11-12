#include<bits/stdc++.h>
using namespace std;
bool pd(int s1,int s2,int s3){
	if(s1+s2+s3>max(max(s1,s2),s3)*2){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long s=0;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(pd(a[i],a[j],a[k])){
					s++;
					s%=998244353;
				}
			}
		}
	}
	cout<<s;
	
	return 0;
} 
