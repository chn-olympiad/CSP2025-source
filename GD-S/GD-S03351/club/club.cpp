#include<bits/stdc++.h>
using namespace std;
const int N=100005;
bool pan(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		int ce1[N]={0},ce2[N]={0},ce3[N]={0};
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&ce1[i],&ce2[i],&ce3[i]);
		}
		int cnt=0;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			if(ce3[i]!=0){
				flag1=0;
				flag2=0;
				break;
			}else if(ce2[i]!=0){
				flag1=0;
				break;
			}
		}
		if(flag1){
			sort(ce1+1,ce1+n+1,pan);
			for(int i=1;i<=n/2;i++){
				cnt+=ce1[i];
			}
			cout<<cnt<<endl;
		}
		else{
			int mk1=0,mk2=0,mk3=0;
			for(int i=1;i<=n;i++){
				int p=max(ce1[i],max(ce2[i],ce3[i]));
				if(p==ce1[i] && mk1+1<=n/2){
					mk1++;
					cnt+=ce1[i];
				}else{
					p=max(ce2[i],ce3[i]);
					if(p==ce2[i] && mk2+1<=n/2){
						mk2++;
						cnt+=ce2[i];
					}else{
					p=ce3[i];
					mk3++;
					cnt+=ce3[i];
					}
				}
			}
			cout<<cnt<<endl;
		}
		t--;
	}
} 
