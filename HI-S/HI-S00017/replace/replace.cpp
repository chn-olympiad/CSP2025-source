#include<bits/stdc++.h>

using namespace std;

int n,q;
string s1[10005],s2[10005],s11[10005],s12[10005],t1,t2,s4;

int kmp(int index,int z){
	int l=z,ind=0;
	bool flag=false;
	while(l+ind<t1.size()){
		while(l+ind<t1.size()&&s1[index][ind]==t1[l+ind]){
			if(ind+1==s1[index].size()){
				flag=true;
				ind=t1.size()-l;
				break;
			}
			ind++;
		}
		l++;
	}
	if(flag){
		return l-1;
	}else{
		return -1;
	}
}

void change(int index,int l){
	for(int i=l;i-l<s2[index].size();i++){
		s4[i]=s2[index][i-l];
	}
}

bool pp(){
	for(int i=0;i<t2.size();i++){
		if(t2[i]!=s4[i]){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];

	}
	
	for(int i=0;i<q;i++){
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int j=0;j<n;j++){
			int num=kmp(j,0);
			while(num!=-1){
				s4=t1;
				change(j,num);
				if(pp()){
					ans++;
					break;
				}else{
					num=kmp(j,num+1);
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}


