#include<bits/stdc++.h>
using namespace std;
int a[5000];
int n,k,ans=0;
int turn_and_xor(int a,int b){
	string sa="",sb="",sc="";
	while(a){
		int e=a%2;
		sa=(char)e+sa;
		a/=2;
	}
	while(b){
		int e=b%2;
		sb=(char)e+sb;
		b/=2;
	}
	if(sa.length()>sb.length()){
		for(int i=1;i<=sa.length()-sb.length();i++)sb='0'+sb;
	}
	else {
		for(int i=1;i<=sb.length()-sa.length();i++)sa='0'+sa;
	}
	for(int i=0;i<sa.length();i++){
		if(sa[i]==sb[i])sc='0'+sc;
		else sc='1'+sc;
	}
	int log=1,re=0;
	for(int i=0;i<sc.length();i++){
		re+=(sc[i]-'0')*log;
		log*=2;
	}
	return re;
}
int t[500];
void f(int ar,int n,int r){
	if(ar==n){
		int i=0,c;
		while(t[i]){
			c=a[t[i-1]];
			for(int j=t[i-1];j<t[i]+t[i-1];j++){
				c=turn_and_xor(c,a[j]);
			}
			if(c!=k)return;
			t[i]+=t[i-1];
		}
		ans++;
	}
	else for(int i=1;i<=n-ar;i++){
		t[r]=i;
		k++;
		f(ar+i,n,r);
	    }
}
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	
	fin>>n>>k;
	
	for(int i=0;i<n;i++){
		fin>>a[n];
	}
	for(int i=1;i<=n;i++){
		t[0]=i;
		f(i,n,1);
	}
	fout<<ans;
	fin.close();
	fout.close();
}
