#include<bits/stdc++.h>
using namespace std;
const int M = 200020;
int n,q;
string s1[M],s2[M],t1,t2;
int po1[M],po2[M];
void create();
int fb(string t){
	for(int i=0;i<t.length();i++){
		if(t[i]=='b') return i;
	}
	return -1;
}
int solve(string t1,string t2);
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	create();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

int solve(string t1,string t2){
	int pos1=fb(t1);
	int pos2=fb(t2);
	int cnt = 0;
	for(int i=1;i<=n;i++) if((pos1-pos2) == (po1[i]-po2[i]) && pos1>=po1[i] && t1.length()-pos1>=s1[i].length()-po1[i]) cnt++;
	return cnt;
}
void create(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		po1[i]=fb(s1[i]);
		po2[i]=fb(s2[i]);
	}
	for(int j=1;j<=q;j++){
		cin>>t1>>t2;
		if(fb(t1)==-1) cout<<'0'<<endl;
		else cout<<solve(t1,t2)<<endl;
	}
}
