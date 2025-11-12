#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;
int n,t;
int m[N][4];

int dfs(int c1,int c2,int c3,int total,int ren){
	int t1,t2,t3;
	if(ren>n){
		return total;
	}
	
	if(c1){
		t1 =dfs(c1-1,c2,c3,total+m[ren][1],ren+1);
	}
	if(c2){
		t2 =dfs(c1,c2-1,c3,total+m[ren][2],ren+1);
	}
	if(c3){
		t3 =dfs(c1,c2,c3-1,total+m[ren][3],ren+1);
	}
	return max(t1,max(t2,t3));

} 

int dfs2(int c1,int c2,int total,int ren){
	int t1,t2;
	if(ren>n){
		return total;
	}
	
	if(c1){
		t1 =dfs2(c1-1,c2,total+m[ren][1],ren+1);
	}
	if(c2){
		t2 =dfs2(c1,c2-1,total+m[ren][2],ren+1);
	}
	
	return max(t1,t2);

} 


void run(){
	cin>>n;
	
	
	int swi=2;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&m[i][1],&m[i][2],&m[i][3]);
		if(m[i][2]!=0&&swi==2){
			swi=1;
		}
		if(m[i][3]!=0&&swi){
			swi=0;
		}
		/*
		if(m[i][1]>=m[i][2]&&m[i][1]>m[i][3]){
			s[1][0]++;
			s[1][++t1]=i;
		}
		
		if(m[i][2]>m[i][1]&&m[i][2]>=m[i][3]){
			s[2][0]++;
			s[2][++t2]=i;
		}
		if(m[i][3]>m[i][2]&&m[i][3]>=m[i][1]){
			s[3][0]++;
			s[3][++t3]=i;
		}
		int tot;
		if(m[i][3]==m[i][2]&&m[i][3]==m[i][1]){
			tot+=m[i][1];
		}
		if(s[1][0]>n/2){
		}*/
	}
	if(swi==2){
		int s[N],tot=0;
		
		for(int i=1;i<=n;i++){
			s[i]=m[i][1];
		}
		sort(s+1,s+1+n);
		for(int i=n;i>n/2;i--){
			//cout<<s[i];
			tot+=s[i];
			//cout<<s[i]<<endl;
		
		}
		cout<<tot<<endl;
	}else if(swi==1){
		cout<<dfs2(n/2,n/2,0,1)<<endl;
	}else if(swi==0){
		cout<<dfs(n/2,n/2,n/2,0,1)<<endl;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		run();
		t--;
	}
	//system("fc club.out club3.ans");
	return 0;
	
}
