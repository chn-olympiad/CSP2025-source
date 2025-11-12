#include<bits/stdc++.h> 
using namespace std;
struct st{
	int val;
	int club;
	int stud; 
};
bool cmp(st a,st b){
	return a.val>b.val;
}
//总排（捆绑所属学生、所属社团 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int sum=0;
		int n;
		cin>>n;
		int maxx=n/2;
		bool flag[n];
		vector<st> stu(3*n);
		for(int i=0;i<3*n;++i){
			flag[i]=false;
			cin>>stu[i].val;
			stu[i].club=i%3;//1,2,0
			stu[i].stud=i/3;//0,1,...n-1
		}
		int aa=0, bb=0, cc=0;
		sort(stu.begin(),stu.end(),cmp);
		for(int i=0;i<3*n;++i){
//			printf("debug aa:%d\n",aa);
//			printf("debug bb:%d\n",bb);
//			printf("debug cc:%d\n",cc);
//			printf("debug maxx:%d\n",maxx);
//			printf("debug stu[i].val:%d\n",stu[i].val);
//			printf("debug stu[i].club:%d\n",stu[i].club);
//			printf("debug stu[i].stud:%d\n",stu[i].stud);
			if(stu[i].club==0&&aa!=maxx){
				if(!flag[stu[i].stud]){
					aa++;sum+=stu[i].val;
					flag[stu[i].stud]=true;
//					printf("enter sum a:%d\n",sum);
				}
			}
			else if(stu[i].club==1&&bb!=maxx){
				if(!flag[stu[i].stud]){
					bb++;sum+=stu[i].val;
					flag[stu[i].stud]=true;
//					printf("enter sum b:%d\n",sum);
				}
			}
			else if(stu[i].club==2&&cc!=maxx){
				if(!flag[stu[i].stud]){
					cc++;sum+=stu[i].val;
					flag[stu[i].stud]=true;
//					printf("enter sum c:%d\n",sum);
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
//炸了  Dp不太会· 