#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod1=1e9+7,mod2=998244353,N=5e6+5;
int powe[N][2];

vector<int> find(string a,string b){
	ll hash1=0,hash2=0;
	vector<int> res;
	for(int i=0;i<b.size();i++){
		hash1=((b[i]-'a')+hash1*37%mod1)%mod1;
		hash2=((b[i]-'a')+hash2*37%mod2)%mod2;
	}
	cout<<hash1<<' '<<hash2<<' '<<powe[b.size()][0]<<' '<<powe[b.size()][1]<<'\n';
	for(ll i=0,hh1=0,hh2=0,nhh1=0,nhh2=0;i<a.size();i++){
		hh1=((a[i]-'a')+hh1*37%mod1)%mod1;
		hh2=((a[i]-'a')+hh2*37%mod1)%mod2;
		if(i>=b.size()){
			nhh1=((a[i-b.size()]-'a')*powe[b.size()][0]%mod1+nhh1*37%mod1)%mod1;
			nhh2=((a[i-b.size()]-'a')*powe[b.size()][1]%mod2+nhh2*37%mod1)%mod2;
		}
		if(i>=b.size()-1){
			cout<<hh1<<' '<<hh2<<' '<<nhh1<<' '<<nhh2<<'\n';
			if((hh1==(hash1+nhh1)%mod1)&&(hh2==(hash2+nhh2)%mod2))res.push_back(i);
		}
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	powe[0][0]=powe[0][1]=1;
	for(int i=1;i<N;i++)powe[i][0]=powe[i-1][0]*37%mod1,powe[i][1]=powe[i-1][1]*37%mod2;
//	vector<int> test=find("aabascbcbcba","cbc");
//	for(int i=0;i<test.size();i++)cout<<test[i]<<' ';
	//time is over
	return 0;
}
/*
We drift through the heaven,ha te na i o mo i
Filled with the love from up above
He guides my travel,ki se ki ko ku ge n
Shed the tear and leap, to a new world
*/
