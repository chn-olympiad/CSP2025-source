#include<iostream>
#include<string>
using namespace std;

int a[5000005][2];
string s1,s2;
int find(string s){
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='b') return i+1;
	}
	return 0;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int x=find(s1),y=find(s2);
		if(y-x>0) a[y-x][1]++;
		if(y-x<0) a[x-y][0]++;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int x=find(s1),y=find(s2);
		if(y-x>0) cout<<a[y-x][1];
		if(y-x<0) cout<<a[x-y][0];
		cout<<endl;
	}
	return 0;
}
