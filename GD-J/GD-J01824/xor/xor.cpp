#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int deep;
int nowf=0;
int size;
int k;
vector<int> allq; 
int oxor(vector<int>& q){
	int res=0;
	for(int n=1;n<=q.size();n+2){
		res+=q.at(n-1)^q.at(n);
	}
	return res;
}
ull getx(vector<int>& q);
ull getx_helper(vector<int>& q){
	if(q.size()==0||deep<3){
		--deep;
		return 0;
	}
	while(true){
		
	}
}
int main() {
	FILE* in=freopen("gg.in","r",stdin);
	FILE* out=freopen("gg.out","w",stdout);
	int nu;
	int cho=0;
	vector<int> q;
	
	cin>>nu>>k;
	deep=nu;
	size=nu;
	for(int n=0;n!=nu;++n){
		int buff;
		cin>>buff;
		q.push_back(buff);
	}
	if(q.size()==2)
	{
		int rr=0;
		if(q.at(0)^q.at(1)==k){
			rr=1;
			return 0;
		}
		if(q.at(0)==k)
			rr++;
		if(q.at(1)==k)
			rr++;
		
	}
	 
	fclose(in);
	fclose(out);
} 
