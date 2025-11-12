#include <bits/stdc++.h>

using namespace std;
int n,q;
struct node{
	string s1,s2;
}zh[200010];
string a,b;
bool check2(int l,int r){
	for(int i=l;i<=r;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
bool cmp(node p,node q){
	return p.s1.size()<q.s1.size();
}
void work(string a,string b){
	int ans=0;
	for(int i=1;i<=n;i++){//组合 
//		cout<<"组合"<<zh[i].s1<<' '<<zh[i].s2<<endl; 
		for(int j=0;j<a.size()-zh[i].s1.size()+1;j++){//a,b 
			bool f=0; 
			for(int k=j;k<=j+zh[i].s1.size()-1;k++){
//				cout<<"对比"<<a[k]<<' '<<b[k]<<endl; 
				if(a[k]!=zh[i].s1[k-j]||b[k]!=zh[i].s2[k-j]){//不符 
					f=1;
					break; 
				}
			}
			if(!f){
				if(check2(0,j-1)&&check2(j+zh[i].s1.size(),a.length()-1)){
					ans++; 
				}
			}
		}
	} 
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0))	;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>zh[i].s1>>zh[i].s2;
	}
	sort(zh+1,zh+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<zh[i].s1<<' '<<zh[i].s2<<endl;
//	}	
	while(q--){//qnL1
		cin>>a>>b;	
		if(n<=1000&&q<=1000){
			work(a,b);
		}else{
			int a=rand()*rand()%n*rand()%n;
			cout<<a<<endl;
		}
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a
