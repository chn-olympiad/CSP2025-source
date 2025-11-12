#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int j=1;j<=T;j++){
	int c[114514][4]={0},ans=0,c4[114514]={0},c5[4]={0};
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)cin>>c[i][1]>>c[i][2]>>c[i][3];
	for(int i=1;i<=a;i++){
		if((c[i][1]>=c[i][2]&&c[i][2]>=c[i][3])||(c[i][1]>=c[i][3]&&c[i][3]>=c[i][2])){
			c5[1]++;ans+=c[i][1];continue;
		}if((c[i][2]>=c[i][1]&&c[i][1]>=c[i][3])||(c[i][2]>=c[i][3]&&c[i][3]>=c[i][1])){
			c5[2]++;ans+=c[i][2];continue;
		}if((c[i][3]>=c[i][2]&&c[i][2]>=c[i][1])||(c[i][3]>=c[i][1]&&c[i][1]>=c[i][2])){
			c5[3]++;ans+=c[i][3];
		}
	}if(c5[1]>a/2){
		for(int i=1;i<=a;i++){
			c4[i]=min(c[i][1]-c[i][2],c[i][1]-c[i][3]);
		}sort(c4+1,c4+a+1);
		int line=1;
		while(c4[line]<0)line++;
		for(int i=line;c5[1]>a/2;c5[1]--,i++){
			ans-=c4[i];
		}cout<<ans<<endl;
	}else if(c5[2]>a/2){
		for(int i=1;i<=a;i++){
			c4[i]=min(c[i][2]-c[i][3],c[i][2]-c[i][1]);
		}sort(c4+1,c4+a+1);
		int line=1;
		while(c4[line]<0)line++;
		for(int i=line;c5[2]>a/2;c5[2]--,i++){
			ans-=c4[i];
		}cout<<ans<<endl;
	}else if(c5[3]>a/2){
		for(int i=1;i<=a;i++){
			c4[i]=min(c[i][3]-c[i][2],c[i][3]-c[i][1]);
		}sort(c4+1,c4+a+1);
		int line=1;
		while(c4[line]<0)line++;
		for(int i=line;c5[3]>a/2;c5[3]--,i++){
			ans-=c4[i];
		}cout<<ans<<endl;
	}else cout<<ans<<endl;
	}
}