#include<bits/stdc++.h>
using namespace std;
int x[200005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x[i];
	}
	if(b==0){
		
		cout<<a/2;
		return 0;
	}
	if(b==1){
		for(int i=0;i<a;i++){
			if(x[i]==1){
				ans++;
			}else if(x[i]!=x[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	return 0;
}