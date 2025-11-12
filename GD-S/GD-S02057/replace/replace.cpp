#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
map<int,int> mp;
map<string,string> mm;
struct node{
	string s1,s2;
}a[N];
string t1,t2;
bool check(int x,int y){
	string c1=t1.substr(x,y-x),c2=t2.substr(x,y-x);
	if(mm[c1]==c2) return true;
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin >> a[i].s1 >> a[i].s2;
		mm[a[i].s1]=a[i].s2;
	} 
	while(q--){
		cin >> t1 >> t2;
		int ans=0;
		int len1=t1.size(),len2=t2.size();
		if(len1!=len2){
			printf("0\n");
			continue;
		}
		for(int i=0,j=len1;i<j;i++,j--){
			if(check(i,j)){
				ans++;
				
			} 
			if(t1[i]!=t2[i]){
				if(t1[j-1]!=t2[j-1]) break;
				else i--;
			}else{
				if(t1[j-1]!=t2[j-1]) j++;
			}
		}
		printf("%d\n",ans);
		
	}
		
	return 0;
} 
