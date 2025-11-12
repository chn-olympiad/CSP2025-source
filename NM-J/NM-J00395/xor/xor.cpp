#include<bits/stdc++.h>
using namespace std;
int n,m,x[500007],jg;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
    if(m!=0&&m!=1){
		cout<<0<<endl;return 0;
	}for(int i=1;i<=n;i++){
		cin>>x[i];
	}if(m==0){
		for(int i=1;i<=n;i++){
			if(x[i]==0)jg++;
			else {
				if(x[i-1]==1){
					jg++;
					if(x[i+1]==1){i++;}
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(x[i]==1)jg++;
		}
	}cout<<jg<<endl;
    return 0;
}
