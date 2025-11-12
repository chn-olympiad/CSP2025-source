#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,ans[N],cnt=0;
struct node{
	int e1,e2,e3,num;
}q[N];
bool vis[N];
bool cmp1(node a,node b){
	return a.e1>b.e1;
}
bool cmp2(node a,node b){
	return a.e2>b.e2;
}
bool cmp3(node a,node b){
	return a.e3>b.e3;
}
bool check(int m){
	for(int i=0;i<m;i++){
		if(!vis[i]){
			return true;
		}
	}
	return false;
}
//5 point 
bool A(int m){
	for(int i=0;i<m;i++){
		if(q[i].e2!=0||q[i].e3!=0){
			return false;
		}
	}
	return true;
}
//15 point
bool B(int m){
	for(int i=0;i<m;i++){
		if(q[i].e3!=0){
			return false;	
		}
	}
	return true;
}
//? point
void tanxin(int m){
	sort(q,q+m,cmp1);
	for(int i=0;i<m;i++){
		if(!vis[q[i].num]){
			vis[q[i].num]=1;
			ans[cnt]+=q[i].e1;
			break;
		}
	}
	sort(q,q+m,cmp2);
	for(int i=0;i<m;i++){
		if(!vis[q[i].num]){
			vis[q[i].num]=1;
			ans[cnt]+=q[i].e2;
			break;
		}
	}
	sort(q,q+m,cmp3);
	for(int i=0;i<m;i++){
		if(!vis[q[i].num]){
			vis[q[i].num]=1;
			ans[cnt]+=q[i].e3;
			break;
		}
	}		
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>q[i].e1>>q[i].e2>>q[i].e3;
			q[i].num=i;
		}
		//5 point A
		if(A(m)){
			int solve=m/2;
			sort(q,q+m,cmp1);
			for(int i=0;i<solve;i++){
				ans[cnt]+=q[i].e1;
			}
		}
		//5 point m=2
		else if(m==2){
			int mxx=0;
			if(q[0].e1+q[1].e2>mxx)mxx=q[0].e1+q[1].e2;
			if(q[0].e1+q[1].e3>mxx)mxx=q[0].e1+q[1].e3;
			if(q[0].e2+q[1].e1>mxx)mxx=q[0].e2+q[1].e1;
			if(q[0].e2+q[1].e3>mxx)mxx=q[0].e2+q[1].e3;
			if(q[0].e3+q[1].e1>mxx)mxx=q[0].e3+q[1].e1;
			if(q[0].e3+q[1].e2>mxx)mxx=q[0].e3+q[1].e2;
			ans[cnt]=mxx;
		}
		//5 point m=4
		else if(m==4){
			int mxx=0;
			if(q[0].e1+q[1].e1+q[2].e2+q[3].e2>mxx)mxx=q[0].e1+q[1].e1+q[2].e2+q[3].e2;
			if(q[0].e1+q[1].e1+q[2].e2+q[3].e3>mxx)mxx=q[0].e1+q[1].e1+q[2].e2+q[3].e3;
			if(q[0].e1+q[1].e1+q[2].e3+q[3].e2>mxx)mxx=q[0].e1+q[1].e1+q[2].e3+q[3].e2;
			if(q[0].e1+q[1].e1+q[2].e3+q[3].e3>mxx)mxx=q[0].e1+q[1].e1+q[2].e3+q[3].e3;
			if(q[0].e1+q[1].e2+q[2].e1+q[3].e2>mxx)mxx=q[0].e1+q[1].e2+q[2].e1+q[3].e2;
			if(q[0].e1+q[1].e2+q[2].e1+q[3].e3>mxx)mxx=q[0].e1+q[1].e2+q[2].e1+q[3].e3;
			if(q[0].e1+q[1].e2+q[2].e2+q[3].e1>mxx)mxx=q[0].e1+q[1].e2+q[2].e2+q[3].e1;
			if(q[0].e1+q[1].e2+q[2].e2+q[3].e3>mxx)mxx=q[0].e1+q[1].e2+q[2].e2+q[3].e3;
			if(q[0].e1+q[1].e2+q[2].e3+q[3].e1>mxx)mxx=q[0].e1+q[1].e2+q[2].e3+q[3].e1;
			if(q[0].e1+q[1].e2+q[2].e3+q[3].e2>mxx)mxx=q[0].e1+q[1].e2+q[2].e3+q[3].e2;
			if(q[0].e1+q[1].e2+q[2].e3+q[3].e3>mxx)mxx=q[0].e1+q[1].e2+q[2].e3+q[3].e3;
			if(q[0].e1+q[1].e3+q[2].e1+q[3].e2>mxx)mxx=q[0].e1+q[1].e3+q[2].e1+q[3].e2;
			if(q[0].e1+q[1].e3+q[2].e1+q[3].e3>mxx)mxx=q[0].e1+q[1].e3+q[2].e1+q[3].e3;
			if(q[0].e1+q[1].e3+q[2].e1+q[3].e2>mxx)mxx=q[0].e1+q[1].e3+q[2].e1+q[3].e2;
			if(q[0].e1+q[1].e3+q[2].e2+q[3].e1>mxx)mxx=q[0].e1+q[1].e3+q[2].e2+q[3].e1;
			if(q[0].e1+q[1].e3+q[2].e2+q[3].e2>mxx)mxx=q[0].e1+q[1].e3+q[2].e2+q[3].e2;
			if(q[0].e1+q[1].e3+q[2].e2+q[3].e3>mxx)mxx=q[0].e1+q[1].e3+q[2].e2+q[3].e3;
			if(q[0].e1+q[1].e3+q[2].e3+q[3].e1>mxx)mxx=q[0].e1+q[1].e3+q[2].e3+q[3].e1;
			if(q[0].e1+q[1].e3+q[2].e3+q[3].e2>mxx)mxx=q[0].e1+q[1].e3+q[2].e3+q[3].e2;
			if(q[0].e2+q[1].e1+q[2].e1+q[3].e2>mxx)mxx=q[0].e2+q[1].e1+q[2].e1+q[3].e2;
			if(q[0].e2+q[1].e1+q[2].e1+q[3].e3>mxx)mxx=q[0].e2+q[1].e1+q[2].e1+q[3].e3;
			if(q[0].e2+q[1].e1+q[2].e2+q[3].e1>mxx)mxx=q[0].e2+q[1].e1+q[2].e2+q[3].e1;
			if(q[0].e2+q[1].e1+q[2].e2+q[3].e3>mxx)mxx=q[0].e2+q[1].e1+q[2].e2+q[3].e3;
			if(q[0].e2+q[1].e1+q[2].e3+q[3].e1>mxx)mxx=q[0].e2+q[1].e1+q[2].e3+q[3].e1;
			if(q[0].e2+q[1].e1+q[2].e3+q[3].e2>mxx)mxx=q[0].e2+q[1].e1+q[2].e3+q[3].e2;
			if(q[0].e2+q[1].e1+q[2].e3+q[3].e3>mxx)mxx=q[0].e2+q[1].e1+q[2].e3+q[3].e3;
			if(q[0].e2+q[1].e2+q[2].e1+q[3].e1>mxx)mxx=q[0].e2+q[1].e2+q[2].e1+q[3].e1;
			if(q[0].e2+q[1].e2+q[2].e1+q[3].e3>mxx)mxx=q[0].e2+q[1].e2+q[2].e1+q[3].e3;
			if(q[0].e2+q[1].e2+q[2].e3+q[3].e1>mxx)mxx=q[0].e2+q[1].e2+q[2].e3+q[3].e1;
			if(q[0].e2+q[1].e2+q[2].e3+q[3].e3>mxx)mxx=q[0].e2+q[1].e2+q[2].e3+q[3].e3;
			if(q[0].e2+q[1].e3+q[2].e1+q[3].e1>mxx)mxx=q[0].e2+q[1].e3+q[2].e1+q[3].e1;
			if(q[0].e2+q[1].e3+q[2].e1+q[3].e2>mxx)mxx=q[0].e2+q[1].e3+q[2].e1+q[3].e2;
			if(q[0].e2+q[1].e3+q[2].e1+q[3].e3>mxx)mxx=q[0].e2+q[1].e3+q[2].e1+q[3].e3;
			if(q[0].e2+q[1].e3+q[2].e2+q[3].e1>mxx)mxx=q[0].e2+q[1].e3+q[2].e2+q[3].e1;
			if(q[0].e2+q[1].e3+q[2].e2+q[3].e3>mxx)mxx=q[0].e2+q[1].e3+q[2].e2+q[3].e3;
			if(q[0].e2+q[1].e3+q[2].e3+q[3].e1>mxx)mxx=q[0].e2+q[1].e3+q[2].e3+q[3].e1;
			if(q[0].e2+q[1].e3+q[2].e3+q[3].e2>mxx)mxx=q[0].e2+q[1].e3+q[2].e3+q[3].e2;
			if(q[0].e3+q[1].e1+q[2].e1+q[3].e2>mxx)mxx=q[0].e3+q[1].e1+q[2].e1+q[3].e2;
			if(q[0].e3+q[1].e1+q[2].e1+q[3].e3>mxx)mxx=q[0].e3+q[1].e1+q[2].e1+q[3].e3;
			if(q[0].e3+q[1].e1+q[2].e2+q[3].e1>mxx)mxx=q[0].e3+q[1].e1+q[2].e2+q[3].e1;
			if(q[0].e3+q[1].e1+q[2].e2+q[3].e2>mxx)mxx=q[0].e3+q[1].e1+q[2].e2+q[3].e2;
			if(q[0].e3+q[1].e1+q[2].e2+q[3].e3>mxx)mxx=q[0].e3+q[1].e1+q[2].e2+q[3].e3;
			if(q[0].e3+q[1].e1+q[2].e3+q[3].e1>mxx)mxx=q[0].e3+q[1].e1+q[2].e3+q[3].e1;
			if(q[0].e3+q[1].e1+q[2].e3+q[3].e2>mxx)mxx=q[0].e3+q[1].e1+q[2].e3+q[3].e2;
			if(q[0].e3+q[1].e2+q[2].e1+q[3].e1>mxx)mxx=q[0].e3+q[1].e2+q[2].e1+q[3].e1;
			if(q[0].e3+q[1].e2+q[2].e1+q[3].e2>mxx)mxx=q[0].e3+q[1].e2+q[2].e1+q[3].e2;
			if(q[0].e3+q[1].e2+q[2].e1+q[3].e3>mxx)mxx=q[0].e3+q[1].e2+q[2].e1+q[3].e3;
			if(q[0].e3+q[1].e2+q[2].e2+q[3].e1>mxx)mxx=q[0].e3+q[1].e2+q[2].e2+q[3].e1;
			if(q[0].e3+q[1].e2+q[2].e2+q[3].e3>mxx)mxx=q[0].e3+q[1].e2+q[2].e2+q[3].e3;
			if(q[0].e3+q[1].e2+q[2].e3+q[3].e1>mxx)mxx=q[0].e3+q[1].e2+q[2].e3+q[3].e1;
			if(q[0].e3+q[1].e2+q[2].e3+q[3].e2>mxx)mxx=q[0].e3+q[1].e2+q[2].e3+q[3].e2;
			if(q[0].e3+q[1].e3+q[2].e1+q[3].e1>mxx)mxx=q[0].e3+q[1].e3+q[2].e1+q[3].e1;
			if(q[0].e3+q[1].e3+q[2].e1+q[3].e2>mxx)mxx=q[0].e3+q[1].e3+q[2].e1+q[3].e2;
			if(q[0].e3+q[1].e3+q[2].e2+q[3].e1>mxx)mxx=q[0].e3+q[1].e3+q[2].e2+q[3].e1;
			if(q[0].e3+q[1].e3+q[2].e2+q[3].e2>mxx)mxx=q[0].e3+q[1].e3+q[2].e2+q[3].e2;
			ans[cnt]=mxx;
		}
		//15 point B
		else if(B(m)){
			int t=0;
			for(int i=0;i<m;i+=2){
				int s1=0,s2=0,s3=0;
				if(i%4<2){
					s1+=(q[i].e1+q[i+1].e1);
					s2+=(q[i].e2+q[i+1].e2);
				}
				else{
					s2+=(q[i].e1+q[i+1].e1);
					s1+=(q[i].e2+q[i+1].e2);
				}	
				s3+=max(q[i].e1+q[i+1].e2,q[i].e2+q[i+1].e1);
				if(t==2){
					ans[cnt]+=max(s1,s3);
					if(max(s1,s3)==s3){t=3;}
					else {t=1;}
				}
				else if(t==1){
					ans[cnt]+=max(s2,s3);
					if(max(s2,s3)==s3){t=3;}
					else {t=2;}
				}
				else{
					ans[cnt]+=max(max(s1,s2),s3);
					if(max(max(s1,s2),s3)==s1){t=3;}
					else if(max(s1,s2)==s2){t=2;}
					else {t=1;}
				}
			}
		}
		//10 point (C for lucky)
		else{
			while(check(m)){
				tanxin(m);
			}
			for(int i=0;i<m;i++){
				vis[i]=0;
			}		
		}
		cnt++;
	}
	for(int i=0;i<cnt;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

