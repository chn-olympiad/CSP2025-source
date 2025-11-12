//GZ-00195 安顺市第一高级中学 徐陈乾康
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rt return
const ll INF=1e18;
const int MAXN=1e5+7;

struct Str{
	
	int num; 
	string s1;
	string s2;
	
}n;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int q;
	cin>>n.num>>q;
	for(int i=0;i<q;i++){
		int num=1000000000;
		num=num%n.num;
		if(num<10){
			cout<<num<<'\n';
		}	
		else{
			num=10;
			cout<<num<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
//@WinercatXD 
//is a Neko
//You can find the name in title at LuoGu without "@"
//CCF,it's my second time to play CSP
//This way it's too hard to get the good mark
//And this is my last fighting in my middle-school time
//Could you please give me some tps? 
//Thanks,CCF...
