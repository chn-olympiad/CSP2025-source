#include<bits/stdc++.h>
using namespace std;
int a,b;
vector<int> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	int siz=s.size();
	int sum=0;
	for(int i=1;i<=siz;i++){
		for(int j=siz;j>=1;j--){
			int ans=j-i;
			int num=s[i];
			for(int k=1;k<=ans;k++){
				num&=s[k+i];
			}
			if(num==b) sum+=1;
		}
	}
	cout<<sum;
	return 0;
}