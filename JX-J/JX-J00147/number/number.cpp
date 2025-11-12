#include<bits/stdc++.h>
using namespace std;
string n;
int s[100005],k=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>n;
	int m=n.size();
	for(int i=0;i<m;i++)
		if(n[i]>='0'&&n[i]<='9'){
			k++;
			s[k]=n[i]-'0';
		}
	sort(s+1,s+k+1);
	for(int i=k;i>=1;i--) cout<<s[i];
	return 0;
}
