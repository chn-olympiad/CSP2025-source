#include<bits/stdc++.h>
using namespace std;
int max_num=0;
int pri(int k,int n,int bo[]){
	if((bo[k]+1)>(n/2)){
		return 0;
	}
	return 1;
}
void cgg(int a[][4],int r,int bo[],int n,int new_num,int yn[]){
	if(r==n+1){
		if(new_num>=max_num) max_num=new_num;
		return;
	}
	int new_bo[4]={0};
	for(int i=1;i<=3;i++){
		new_bo[i]=bo[i];
	}
	int new_yn[n+1];
	for(int i=1;i<=n;i++){
		new_yn[i]=yn[i];
	}
	for(int i=1;i<=3;i++){
		if(pri(i,n,bo) && yn[r]){
			new_bo[i]+=1;
			new_yn[r]=0;
			new_num+=a[r][i];
			cout<<r<<' '<<i<<' '<<new_num<<endl;
			cgg(a,r+1,new_bo,n,new_num,new_yn);
		}else{
			cout<<r<<' '<<i<<' '<<new_num<<endl;
			cgg(a,r+1,new_bo,n,new_num,yn);
		}
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		unsigned int n;
		cin>>n;
		int a[n+1][4],bo[4]={0},yn[n+1];
		for(int i=1;i<=n;i++){
			yn[i]=1;	
		}
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			for(int h=1;h<=3;h++){
				int k;	
				cin>>k;
				a[j][h]=k;
			}
		}
		cout<<endl;
		cgg(a,1,bo,n,0,yn);
		cout<<max_num;
		max_num=0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

