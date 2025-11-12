#include<bits/stdc++.h>
using namespace std;
int t,n;
long long maxx=0;
struct san{
	int m1;
	int m2;
	int m3;
}ren[100005];
void bfs(long long x,int y,int s1,int s2,int s3){
	for(int i=1;i<=3;i++){
		if(i==1 && s1<n/2){
			bfs(x+ren[y].m1,y+1,s1+1,s2,s3);
		}
		if(i==2 && s2<n/2){
			bfs(x+ren[y].m2,y+1,s1,s2+1,s3);
		}
		if(i==3 && s3<n/2){
			bfs(x+ren[y].m3,y+1,s1,s2,s3+1);
		}
	}
	if(y==n){
		if(x>maxx) maxx=x;
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>ren[i].m1>>ren[i].m2>>ren[i].m3;
		}
		bfs(0,0,0,0,0);
		cout<<maxx<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
