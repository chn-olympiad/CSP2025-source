#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int m,q;
map<int,int>a;
int n,t1,t2;
string s1[N],s2[N];
int main(){
	cin>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>s1[i]>>s2[i];
		a[s2[i].find('b')-s1[i].find('b')]++;
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		int t1=x.find('b'),t2=y.find('b');
		cout<<a[t2-t1]<<endl;
	}
	return 0;
}/*

不打暴力
不判前后
乱打 

*/ 

