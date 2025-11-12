#include<bits/stdc++.h>
using namespace std;
char a[1000005]={'0'};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sum=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			if(s[i]>=a[0]&&s[i]!='0'){
				for(int i=sum-1;i>0;i--){
					a[i]=a[i-1];
				}
				a[0]=s[i];
			}else{
				int x=sum;
				if(s[i]<=a[sum-1]) a[sum]=s[i];
				while(s[i]>a[x-1]){
					a[x]=a[x-1];
					a[x-1]=s[i];
					x--;
				}
			}
		}
	}
	if(a[0]=='0')return 0;
	for(int i=0;i<sum;i++)cout<<a[i];
	return 0;
} 
