#include<bits/stdc++.h>
using namespace std;
struct s{
	long long int a1,a2,a3;
	bool ab;
	long long int whi,num;
}stu[1000000];
long long int l1,l2,l3;
long long int s1,s2,s3;
long long int jiancha(long long int x,long long int y){
	if(x>y){
		return 0;
	}
	long long int ans=0;
	if((l1+1)<=(y/2)){
		l1+=1;
		ans=max(ans,stu[x].a1+jiancha(x+1,y));
		l1-=1;
	}
	if((l2+1)<=(y/2)){
		l2+=1;
		ans=max(ans,stu[x].a2+jiancha(x+1,y));
		l2-=1;
	}
	if((l3+1)<=(y/2)){
		l3+=1;
		ans=max(ans,stu[x].a3+jiancha(x+1,y));
		l3-=1;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	long long int t;
	cin>>t;
	for(long long int i=1;i<=t;i++){
		long long int n;
		cin>>n;
		for(long long int j=1;j<=n;j++){
			cin>>stu[j].a1>>stu[j].a2>>stu[j].a3;
			stu[j].ab=true;
			stu[j].num=max(stu[j].a1,stu[j].a2);
			stu[j].num=max(stu[j].num,stu[j].a3);
			if(stu[j].num==stu[j].a1){
				stu[j].whi=1;
				l1+=1;
				s1+=stu[j].num; 
			}else if(stu[j].num==stu[j].a2){
				stu[j].whi=2;
				l2+=1;
				s2+=stu[j].num;
			}else{
				stu[j].whi=3;
				l3+=1;
				s3+=stu[j].num;
			}
		}
		if(l1<=(n/2)&&l2<=(n/2)&&l3<=(n/2)){
			cout<<s1+s2+s3;
		}else{
			l1=0;
			l2=0;
			l3=0;
			cout<<jiancha(1,n);
		}
		
	}
	
	return 0;
} 
