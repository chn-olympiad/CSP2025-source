#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//char change1[100][100];//替换的 
//char change2[100][100];
//
//
//char bechange1[100];//被替换的 
//char bechange2[100];
string change1[1000];
string change2[1000];
string bechange1;
string bechange2;

int n,q;
int PP=31;
unsigned long long P[1000];
unsigned long long change1H[1000][1000];
unsigned long long bechange1H[1000];
int ans=0;
int getbe(int l,int r){
	return (bechange1H[r]-bechange1H[l-1]*P[r-l+1]);
}
int getchange(int num,int l,int r){
	return (change1H[num][r]-change1H[num][l-1]*P[r-l+1]);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	P[0]=1;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){//从0开始 
		cin>>change1[i];
		cin>>change2[i];
		for(int i=1;i<=50;i++){
			P[i]=P[i-1]*PP;
		}
		if(change1[i].length()==change2[i].length()){
			for(int j=1;j<=change1[i].length();j++){
				change1H[i][j]=change1H[i][j-1]*PP+change1[i][j-1];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		bechange1="";
		bechange2="";
		memset(bechange1H,0,sizeof(bechange1H)); 
		cin>>bechange1;
		cin>>bechange2;
		for(int j=1;j<=bechange1.length();j++){
			bechange1H[j]=bechange1H[j-1]*PP+bechange1[j-1];
		}
		for(int j=1;j<=n;j++){//从第一个替换串逐一对比 ,j是编号 
			int len=change1[j].length();
			int len_=bechange1.length();
			for(int k=len-1;k<len_;k++){//比对终点 
				int l=k-len+1;//比对起点 
//				cout<<l<<" "<<k<<endl;
				if(getbe(l+1,k+1)==getchange(j,1,len)){
					string tmp;
					tmp=bechange1;
					for(int m=l;m<=k;m++){
						tmp[m]=change2[j][m-l];
					} 
					if(tmp==bechange2){
						ans++;
//						cout<<ans<<endl;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
