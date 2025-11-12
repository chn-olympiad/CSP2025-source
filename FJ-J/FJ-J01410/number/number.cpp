# include <bits/stdc++.h>
using namespace std;
string s;
long long int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	for(int i=0;i<=s.size();i++){
		int z=s[i]-'0';
		
		if(z>=0&&z<=9){
			a[z]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	cout<<"\n";
}
