//GY-S40086 贵阳市第一中学 陶昱泽
#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string n1[200001],n2[200001],q1,q2;
int zhao(string str1,string str2){
	int a=str1.length();
	int b=str2.length();
	int c;
	for(int i=0;i<a-b;i++){
		c=1;
		for(int j=0;j<b;j++){
			if(str1[i+j]!=str2[j]){
				c=0;
				break;
			}
		}
		if(c){
			return i;
		}
	}
	return -1;
}
void asd(string str,int b,int a){
	int c=str.length();
	string str3;
	for(int i=0;i<a;i++){
		str3+=str[i];
	}
	str3+=n2[b];
	a=str.length();
	for(int i=a;i<c;i++){
		str3+=str[i];
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>n1[i]>>n2[i];
	}
	while(q--){
		ans=0;
		cin>>q1>>q2;
		for(int i=1;i<=n;i++){
			int a=zhao(q1,n1[i]);
			if(a>=0){
				asd(q2,i,a);
				if(q1==q2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
