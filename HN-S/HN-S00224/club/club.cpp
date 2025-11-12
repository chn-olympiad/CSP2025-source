#include<bits/stdc++.h>
using namespace std;

int n;

int T;

//int pow_(int n,)
struct stu{
	int id;
	int num;
}node[100];

bool cmp(stu i,stu j){
	return i.num>j.num;
}

void solve1(){
	int chs[10005]={0};
	int t;
	int a1[100005];
	int a2[100005];
	int a3[100005];
	int ans=0;
	memset(chs,0,sizeof(chs));
	int A=1;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
		if(a2[i]!=0){
			A=0;
			//B=0; 
		}else if(a3[i]!=0){
			A=0;
		}
	}
	if(A==1){
		sort(a1,a1+n);
		for(int i=0;i<n/2;i++){
			ans+=i;
		}
		cout<<ans<<endl;
		return;
	}
	if(n<=10){
//			cout<<111111111111<<endl;
		
		for(int i=0;i<pow(3,n+1);i++){
			int a1_=0;
			int a2_=0;
			int a3_=0;
			int tmp=0;
			int cnt=0;
			int flag=1;
			
			chs[0]++;
//				cout<<" "<<chs[0]<<endl;
			while(chs[cnt]>=3){
//					cout<<"whi"<<cnt<<endl;
				chs[cnt]=0;
				chs[cnt+1]+=1; 
				cnt++;
			}
//				
//				for(int x=0;x<10;x++){
//					cout<<chs[x]<<" ";
//				} 
//				cout<<endl;
			for(int j=0;j<n;j++){
				if(chs[j]==0){
					a1_++;
					tmp+=a1[j];
					if(a1_>n/2){
						flag=0;
						break;
					}
				}
				else if(chs[j]==1){
					a2_++;
					tmp+=a2[j];
					if(a2_>n/2){
						flag=0;
						break;
					}
				}
				else{
					a3_++;
					tmp+=a3[j];
					if(a3_>n/2){
						flag=0;
						break;
					}
				}
			}
			if(flag==1){
				ans=max(ans,tmp);
			}
		}
		cout<<ans<<endl;
	}
}

void solve2(){
	int ans=0;
	vector<int>a1;
	vector<int>a2;
	vector<int>a3;
	int now_num[105];
	memset(now_num,0,sizeof(now_num));
	a1.clear();
	a2.clear();
	a3.clear();
//	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a1.push_back(a);
		a2.push_back(b);
		a3.push_back(c);
	}
	

	for(int i=n-1;i>=0;i--){
		
		node[1].id=1;
		node[2].id=2;
		node[3].id=3;
		node[1].num=a1[i];
		node[2].num=a2[i];
		node[3].num=a3[i];
		int flag=1;
		sort(node+1,node+4,cmp);
		for(int j=1;j<4;j++){
			if(flag==0){
				break;
			}
			if(now_num[node[j].id]<=n/2){
				now_num[node[j].id]++;
				ans+=node[j].num;
				flag=0;
			}
		}
	}
	cout<<ans<<endl;
} 


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int role=0;role<T;role++){
		
		//int B=1;
		cin>>n;
		if(n>=30){
			solve2();
		}else{
			solve1();
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
