#include<bits/stdc++.h>
int a[10];
using  namespace std;
int main()
{
	long long b=0,c=0,d=0,e=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout)£»
	string s ;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>=1&&s[i]<=9){
			a[i]++;
			c++;
		}
	}
	for(int i=s.size;i>=0;i--){
		if(a[i]!=0){
	         d=i;
			for(int q=1;q<=a[i];q++){
				d*=10;
			}
			a[i]--;
			e+=d;
			if(a[i]!=0) i++;
		}
		} 
	}
	cout<<e;
	return 0;
}
