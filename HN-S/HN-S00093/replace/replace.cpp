#include<bits/stdc++.h>
using namespace std;
int n,q,e1[200010],e2[200010];
string s1[200010],s2[200010],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int j=0;
		while(s1[i][j]!='b'){
			j++;
		}
		e1[i]=j;
		j=0;
		while(s2[i][j]!='b'){
			j++;
		}
		e2[i]=j;
	}
	int t=0;
	for(int i=1;i<=q;i++){
		t=0;
		cin>>t1>>t2;
		int x1,x2;
		int k=0;
		while(t1[k]!='b'){
			k++;
		}
		x1=k;
		k=0;
		while(t2[k]!='b'){
			k++;
		}
		x2=k;
		for(int j=1;j<=n;j++){
			if(e1[j]<x1&&e2[j]<=x2&&(x1!=x2||s1[j]!=s2[j])&&e1[j]==e2[j]) t++;
		}
		cout<<t<<endl;
	}
	return 0;
}
