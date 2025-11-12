#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int num[500050],ac[500050];
bool check(int i,int j){
	int temp=num[i];
	for(int x=i+1;x<=j;x++){
		temp=temp^num[x];
	}
	return temp==k;
}
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	bool t=false;
	int temp=0;
	for(int i=1;i<=n;i++){
		if(temp>n){
			break;
		}
		else if(t&&temp<=n){
			i=temp;
			t=false;
		}
		for(int j=i;j<=n;j++){
			if(i==j&&num[i]==k){
				ans++;
				break;
			}
			if(check(i,j)){
				ans++;
				t=true,temp=++j;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
