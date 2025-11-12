#include<bits/stdc++.h>
using namespace std;
long T,n,m;
struct Stu{
	int a,b,c,q[4];
	void input(){
		cin>>a>>b>>c;
		q[1]=a-b-c;
		q[2]=b-a-c;
		q[3]=c-a-b;
	}
}stu[100005];
bool cmp11(int a,int b){
	return stu[a].a>stu[b].a;
}
bool cmp12(int a,int b){
	return stu[a].q[1]>stu[b].q[1];
}
bool cmp21(int a,int b){
	return stu[a].b>stu[b].b;
}
bool cmp22(int a,int b){
	return stu[a].q[2]>stu[b].q[2];
}
bool cmp31(int a,int b){
	return stu[a].c>stu[b].c;
}
bool cmp32(int a,int b){
	return stu[a].q[3]>stu[b].q[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int ttt=1;ttt<=T;ttt++){
		cin>>n;
		long long cnt=0;
		m=n/2;
		for(int i=0;i<n;i++) stu[i].input();
	
		vector<int> f1;
		vector<int> f2;
		vector<int> f3;
		for(int i=0;i<n;i++){
			if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c) f1.push_back(i);
			if(stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c) f2.push_back(i);
			if(stu[i].c>=stu[i].b&&stu[i].c>=stu[i].a) f3.push_back(i);
		}
		sort(f1.begin(),f1.end(),cmp11);
		sort(f1.begin(),f1.end(),cmp12);
		sort(f2.begin(),f2.end(),cmp21);
		sort(f2.begin(),f2.end(),cmp22);
		sort(f3.begin(),f3.end(),cmp31);
		sort(f3.begin(),f3.end(),cmp32);
		if(n<=m*3){
			if(f1.size()>m){
				for(int i=m;i<f1.size();i++){
					Stu nn=stu[f1[i]];
					int j[3]={nn.a,nn.b,nn.c};
					sort(j,j+3);
					if(j[1]==nn.b && f2.size()<m){
						f2.push_back(f1[i]);
						f1.erase(f1.begin()+i);
						sort(f2.begin(),f2.end(),cmp21);
						sort(f2.begin(),f2.end(),cmp22);
					}
					else if(j[1]==nn.c && f3.size()<m){
						f3.push_back(f1[i]);
						f1.erase(f1.begin()+i);
						sort(f3.begin(),f3.end(),cmp31);
						sort(f3.begin(),f3.end(),cmp32);
					}
					else{
						if(j[0]==nn.b && f2.size()<m){
							f2.push_back(f1[i]);
							f1.erase(f1.begin()+i);
							sort(f2.begin(),f2.end(),cmp21);
							sort(f2.begin(),f2.end(),cmp22);
						}
						else if(j[0]==nn.c && f3.size()<m){
							f3.push_back(f1[i]);
							f1.erase(f1.begin()+i);
							sort(f3.begin(),f3.end(),cmp31);
							sort(f3.begin(),f3.end(),cmp32);
						}	
					}
				}
			}
			if(f2.size()>m){
				for(int i=m;i<f2.size();i++){
					Stu nn=stu[f2[i]];
					int j[3]={nn.a,nn.b,nn.c};
					sort(j,j+3);
					if(j[1]==nn.a && f1.size()<m){
						f1.push_back(f2[i]);
						f2.erase(f2.begin()+i);
						sort(f1.begin(),f1.end(),cmp11);
						sort(f1.begin(),f1.end(),cmp12);
					}
					else if(j[1]==nn.c && f3.size()<m){
						f3.push_back(f2[i]);
						f2.erase(f2.begin()+i);
						sort(f3.begin(),f3.end(),cmp31);
						sort(f3.begin(),f3.end(),cmp32);
					}
					else{
						if(j[0]==nn.a && f1.size()<m){
							f1.push_back(f2[i]);
							f2.erase(f2.begin()+i);
							sort(f1.begin(),f1.end(),cmp11);
							sort(f1.begin(),f1.end(),cmp12);
						}
						else if(j[0]==nn.c && f3.size()<m){
							f3.push_back(f2[i]);
							f2.erase(f2.begin()+i);
							sort(f3.begin(),f3.end(),cmp31);
							sort(f3.begin(),f3.end(),cmp32);
						}
					}
				}
			}
			if(f3.size()>m){
				for(int i=m;i<f3.size();i++){
					Stu nn=stu[f3[i]];
					int j[3]={nn.a,nn.b,nn.c};
					sort(j,j+3);
					if(j[1]==nn.b && f2.size()<m){
						f2.push_back(f3[i]);
						f3.erase(f3.begin()+i);
						sort(f2.begin(),f2.end(),cmp21);
						sort(f2.begin(),f2.end(),cmp22);
					}
					else if(j[1]==nn.a && f1.size()<m){
						f1.push_back(f3[i]);
						f3.erase(f3.begin()+i);
						sort(f1.begin(),f1.end(),cmp11);
						sort(f1.begin(),f1.end(),cmp12);
					}
					else{
						if(j[0]==nn.b && f2.size()<m){
							f2.push_back(f3[i]);
							f3.erase(f3.begin()+i);
							sort(f2.begin(),f2.end(),cmp21);
							sort(f2.begin(),f2.end(),cmp22);
						}
						else if(j[0]==nn.a && f1.size()<m){
							f1.push_back(f3[i]);
							f3.erase(f3.begin()+i);
							sort(f1.begin(),f1.end(),cmp11);
							sort(f1.begin(),f1.end(),cmp12);
						}
					}
				}
			}
		}
		for(int i=0;i<m;i++){
			if(f1.size()>i) cnt+=stu[f1[i]].a;
			if(f2.size()>i) cnt+=stu[f2[i]].b;
			if(f3.size()>i) cnt+=stu[f3[i]].c;
		}
		cout<<cnt;
		if(ttt!=T) cout<<endl;
	}
	return 0;
} 
