# include<bits/stdc++.h>
using namespace std;
int n[15];
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=1000000;i++){
		if(a[i]<='9'&&a[i]>='0'){
			n[a[i]-'0'+1]++;
		}
	}
	for(int i=10;i>=1;i--){
		for(int j=n[i];j>0;j--){
			cout<<i-1;
		}
	}
	return 0;
}
