#include<bits/stdc++.h>
using namespace std;
int n,q,sum;
struct no{
	string a,b;
}s[200005];
bool cmp(no a,no b){
	return a.a.size()<b.a.size();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q; 
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	sort(s+1,s+n+1,cmp);
	string s1,s2;
	for(int qj=1;qj<=q;qj++){
		sum=0;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i])break;
			for(int j=s1.size();j>i+1;j--){
				if(s1[j]!=s2[j])break;
				for(int l=1;l<=n;l++){
					if(s[l].a.size()>s1.size())break; 
					bool c=1;
					for(int r=i;r<=j;r++){
						if(s[l].a[r-i]!=s1[r])c=0;
					}
					for(int r=i;r<=j;r++){
						if(s[l].b[r-i]!=s2[r])c=0;
					}
					if(c)sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
