//ad astra per aspera 
#include<bits/stdc++.h>

using namespace std;

int n,m,c=0; 
int nu[500005];
bool vis[500005]={};
void init(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nu[i];
	} 
	for(int i=1;i<=n;i++){
		for(int l=0;l<=n-i;l++){
			int st=nu[l];
//			cout<<st<<" ";
			bool isb=false;
			for(int bl=l+1;bl<l+i;bl++){
//				cout<<nu[bl]<<" ";
				if(vis[bl]){
					isb=true;
//					cout<<"b";
					break;
				}
				st=st^nu[bl];
			} 
//			cout<<".."<<st; 
			if(st==m&&!isb){
				c++;
//				cout<<"p";
				for(int j=l;j<l+i;j++){
					vis[j]=true;
				}
			}
//			cout<<endl;
		}
	}
	cout<<c;
	return;
}
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	init(); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//yijiu bigyangli QAQ
