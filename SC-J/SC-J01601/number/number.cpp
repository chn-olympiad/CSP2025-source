#include<bits/stdc++.h>
using namespace std;
int a[100100],i;
string s;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j=0;j<s.size();j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[i]=s[j]-48;
			i++;
		}
	}
	sort(a,a+i,cmd);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(int j=0;j<i;j++)cout<<a[j];
	return 0;
} 
/*
挖掘机里腌萝卜，咿呀咿呀哟
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
挖掘机里腌萝卜，咿呀咿呀哟 
*/