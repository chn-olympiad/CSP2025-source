#include<bits/stdc++.h>
using namespace std;
const int L=2003;
const int  N=1003;
char a[N][L],b[N][L];
int ne[N][L];
int n,q;
int l; 
char s[L],t[L];
char ss[L];
bool cmp(){
	for(int i=1;i<=l;i++){
		if(s[i]!=t[i]) return false;
	}
	return true;
}
void init(){
	int pr;
	for(int i=1;i<=n;i++){
		int m=strlen(a[i]+1);
		ne[i][0]=-1;
		ne[i][1]=0;
		pr=0; 
		for(int j=2;j<=m;j++){
			while(pr&&a[i][j]!=a[i][pr+1]){
				pr=ne[i][pr];
			}
			if(a[i][j]==a[i][pr+1]){
				pr++;
			}
			ne[i][j]=pr;
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=strlen(a[i]+1);j++){
//			cout<<ne[i][j]<<" ";
//		}
//		puts("");
//	}
//初始化KMP正确 
}
vector<int> find(int x){
	//s中找a[x]+1
	vector<int> ans;
	int la=strlen(a[x]+1);
//	cout<<s+1<<" <- "<<a[x]+1<<"\n"; 
	int j=0;
	for(int i=1;i<=l;i++){
		while(j&&s[i]!=a[x][j+1]){
			j=ne[x][j];
		}
//		cout<<s[i]<<" "<<a[x][j+1]<<"\n";
		if(s[i]==a[x][j+1]){
			j++;
		}
//		cout<<x<<" : "<<i<<" "<<j<<" (j)\n";
		if(j==la){
			ans.push_back(i-j+1);
//			cout<<x<<" : "<<i-j+1<<" pos \n";
			j=ne[x][j];
		}
		
	}
	return ans;
//查找字串正确 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",a[i]+1,b[i]+1);
	} 
	init();
	for(int i=1;i<=q;i++){
		scanf("%s%s",s+1,t+1);
		l=strlen(s+1);
		if(l!=strlen(t+1)){
			puts("0");
			continue;
		}
		for(int j=1;j<=l;j++){
			ss[j]=s[j];
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			
			vector<int> pos=find(j);
			for(int p:pos){
				for(int k=p;k<p+strlen(a[j]+1);k++){
					s[k]=b[j][k-p+1];
				}
//				cout<<"p="<<p<<"\n";
//				cout<<a[j]+1<<" (a[j])\n";
//				cout<<strlen(a[j]+1)<<"\n";
//				cout<<s+1<<" "<<t+1<<"\n"; 
				if(cmp()){
					ans++;
				}
				for(int k=p;k<p+strlen(a[j]+1);k++){
					s[k]=ss[k];
				}
			}
//			cout<<"same = "<<pos.size()<<"\n";
		}
		printf("%d\n",ans);
	}//样例1通过 
	return 0;
} 
