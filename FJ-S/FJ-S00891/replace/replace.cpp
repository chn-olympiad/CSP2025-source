#include<iostream>
#include<string>
#include<vector>
using namespace std;

string a[200010];
string b[200010];

int z[10000010];

void kmp(string s){
	z[0]=0;
	for(int i=1;i<s.size();i++){
		int j=z[i-1];
		while(s[j]!=s[i])j=z[j]-1;
		z[i]=j;
	}
}

void solve(int m){
	string s,t;
	cin>>s>>t;
	int n=s.size();
	int l=n,r=-1;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i])l=min(l,i),r=max(r,i);
	}
	string k="";
	for(int i=l;i<=r;i++)k+=s[i];
	for(int i=0;i<m;i++)k+='#',k+=a[i];
//	return ;
	kmp(k);
	int cnt=0,ans=0;
	vector<int>fl;
	for(int i=r-l+2;i<k.size();i++){
		if(k[i]=='#'){
			int fl2=0;
			for(auto x:fl){
				if(l-x<0)continue;
				if(l+a[cnt].size()-x>=n)continue;
				for(int j=l-x;j<l+a[cnt].size()-x;j++)s[j]=b[cnt][j-(l-x)];
				fl2=s==t;
			}
			ans+=fl2;
			cnt++;
		}
		else if(z[i]==r-l+1)fl.push_back(i);
//		cout<<i<<" ";
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("replace.in","r",stdout);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
//	cout<<n<<" "<<q
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	while(q--)solve(n);
}
