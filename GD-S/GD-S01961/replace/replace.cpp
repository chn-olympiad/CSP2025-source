#include<bits/stdc++.h>
using namespace std;
string t(string a,string b,int i){
	string x=a;
	for(int j=0;j<b.size();j+=1){
		x[i+j]=b[j];
	}
	return x;
}
bool check(string a,string b,int i){
	for(int j=0;j<b.size();j+=1){
		if(a[i+j]!=b[j])return 0;
	}return 1;
}
int main(){
	ifstream fin("replace.in");
	ofstream fout("replace.out");
	int n,q;
	fin>>n>>q;
	string a[n][2];
	for(int i=0;i<n;i+=1){
		fin>>a[i][0]>>a[i][1];
	}
	string x,y;int w;
	for(int i=0;i<q;i+=1){
		fin>>x>>y;
		w=0;
		for(int j=0;j<x.size();j++)
		for(int h=0;h<n;h++)
		if(x[j]==a[h][0][0]&&t(x,a[h][1],j)==y&&check(x,a[h][0],j)){
			w++;
		}
	fout<<w<<endl;
	}
	return 0;
}

