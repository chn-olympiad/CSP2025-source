#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int ca(string a,string b){
	int z;
	for(int i=0;i<a.length();i++){
		int d=int(a[i]);
		int h=int(b[i]);
		if(d!=h){
			z+=d*26+h;
		}
	}
	return z;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int a,s;
	cin>>a>>s;
	
	string s1[2000],s2[2000];
	string tar1[2000],tar2[2000];
	for(int i=1;i<=a;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=s;i++){
		cin>>tar1[i]>>tar2[i];
		
	}
	for(int i=1;i<=s;i++){
		int sum=0;
		int k=ca(tar1[i],tar2[i]);
		for(int j=1;j<=a;j++){
			int q=ca(s1[j],s2[j]);
			if(q==k){
				sum++;
			}
	}
	cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
