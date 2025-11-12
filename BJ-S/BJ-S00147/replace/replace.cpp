#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

long long ans=0;

int p[N][4],cs[N];
int n;

bool check(string a,string b,int p){
	for(int i=p;i<p+int(b.size());i++){
		if(a[i]!=b[i-p]) return 0;
	}
	return 1;
}

string gen(string a,string b,int p){
		string news;
		for(int i=0;i<p;i++){
			news+=a[i];
		}
		news+=b;
		for(int i=p+int(b.size());i<int(a.size());i++){
			news+=a[i];
		}
		return news;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	vector<string> s1;
	vector<string> s2;
	vector<string> t1;
	vector<string> t2;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string str1,str2;
		cin>>str1>>str2;
		s1.push_back(str1);
		s2.push_back(str2);
	}
	for(int i=1;i<=q;i++){
		string str1,str2;
		cin>>str1>>str2;
		t1.push_back(str1);
		t2.push_back(str2);
	}
	long long ans=0;
	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<int(s1[i].size());k++){
				if(check(t1[i],s1[j],k)){
					string newone=gen(t1[i],s2[j],k);
					if(newone==t2[i]) ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
    return 0;
}
