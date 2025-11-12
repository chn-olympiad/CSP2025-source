#include <bits/stdc++.h>
using namespace std;
int n,m,b;
int s1[100000],s[100000];
int inn;
int j123;
int a;
struct yuangon{
	int ren;
	int jici;
}yuan[100005];

void dfs(int nnn){
	if(nnn==m){
		a++;
	}
	for(int i=0;i<n;i++){
		if(s[i]==1 and yuan[nnn].jici<yuan[nnn].ren){
			dfs(nnn+1);
		}else{
			yuan[nnn].jici++;
		}
	}
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>b;
	while(b>0){
		s1[inn]=b%10;
		b=b/10;
		inn++;
	}
	for(int i=0;i<n;i++){
		cin>>yuan[i].ren;
	}
	
	for(int i=inn-1;i>=0;i--){
		s[j123]=s1[i];
		j123++;
	}
	dfs(0);
	cout<<a;
	
	
	return 0;
}
