

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

#define ll long long
const ll maxn=200006;
ll n,q;ll l,r,correct=0;
string s[maxn][2];
int set(string a,string b){
	l=0,r=1;int count=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i])continue;
		else if(a[i]!=b[i]){
			count++;
		}
	}
	return count;
}

bool check(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])return false;
		else continue;
	}
	return true;
}

void kmp(string a,string b,int start){
	int pos=-1;int j=0;
	correct=0;
	for(int i=start;i<a.size();i++){
		if(a[i]==b[j] && pos==-1){
			if(j==b.size()-1){
				correct=1;
				return;
			}			
			pos=1;j++;l=i;
		}
		else if(pos==1 && a[i]==b[j]){
			if(j==b.size()-1){
				correct=1;
				return;
			}
			j++;
		}
		else{
			pos=-1;
			l=-1;j=0;
		}
	}
	
	
}

int calculate(string a,string b){
	ll ans=0;
	int count=set(a,b);
	for(int i=1;i<=n;i++){
		if(s[i][0].size()>a.size() || a.size()!=b.size() || count>s[i][0].size())continue;
		else{
	
			l=0;
			string tmpa;
			for(int j=0;j<a.size();j++){
				tmpa=a;
				
				kmp(a,s[i][0],j);
				
				if(correct==1 && l!=-1){
//					cout<<l<<" "<<l+s[i][0].size()-1<<endl;
//cout<<endl<<i<<234<<endl;
					int k=0;
					j=l;
					for(int v=l;v<=l+s[i][0].size()-1;v++){
				
						tmpa[v]=s[i][1][k];
						k++;
						
					}
					//if(i==2)cout<<tmpa;
					if(check(tmpa,b)){
						ans++;break;
					}	
				}			
			}

		}
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;

	string w;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=1;j++){
			cin>>s[i][j];
		}
	}
	while(q--){
		
		string a,b;
		l=0,r=0;
		cin>>a>>b;
		cout<<calculate(a,b)<<endl;

	}
	
	
	return 0;
} 
