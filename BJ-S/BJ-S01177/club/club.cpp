#include<bits/stdc++.h>
using namespace std;
struct three{
	int a1;
	int a2;
	int a3;
	int abc;
	int x2;
	int x3;
};
int main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int kk[5]={0};
		three b[n+5]={{0,0,0,0}};
		for(int i=1;i<=n;i++){
			cin>>b[i].a1>>b[i].a2>>b[i].a3;
			if(b[i].a1>=b[i].a2&&b[i].a1>=b[i].a3){
				b[i].abc=1;
				if(b[i].a2>=b[i].a3){
					b[i].x2=2;
					b[i].x3=3;
				}else{
					b[i].x2=3;
					b[i].x3=2;
				}
			}else if(b[i].a2>=b[i].a1&&b[i].a2>=b[i].a3){
				b[i].abc=2;
				if(b[i].a1>=b[i].a3){
					b[i].x2=1;
					b[i].x3=3;
				}else{
					b[i].x2=3;
					b[i].x3=1;
				}
			}else if(b[i].a3>=b[i].a2&&b[i].a3>=b[i].a1){
				b[i].abc=3;
				if(b[i].a2>=b[i].a1){
					b[i].x2=2;
					b[i].x3=1;
				}else{
					b[i].x2=1;
					b[i].x3=2;
				}
			}
			kk[b[i].abc]++;
		}
		int w=n/2;
		if(kk[1]<=w && kk[2]<=w && kk[3]<=w){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(b[i].abc==1){
					cnt+=b[i].a1;
				}
				if(b[i].abc==2){
					cnt+=b[i].a2;
				}
				if(b[i].abc==3){
					cnt+=b[i].a3;
				}
			}
			cout<<cnt<<endl;
		}else{
			if(kk[1]>w){
				for(int i=1;i<=kk[1];i++){
					if(b[i].abc!=1){
						for(int j=kk[1]+1;j<=n;j++){
							if(b[j].abc==1){
								swap(b[i],b[j]);
								break;
							}
						}
					}
				}
				for(int i=1;i<=kk[1];i++){
					for(int j=1;j<kk[1];j++){
						int cha=0;
						if(b[j].x2==2){
							cha=b[j].a1-b[j].a2;
						}
						if(b[j].x2==3){
							cha=b[j].a1-b[j].a3;
						}
						int cha2=0;
						if(b[j+1].x2==2){
							cha2=b[j+1].a1-b[j+1].a2;
						}
						if(b[j].x2==3){
							cha2=b[j+1].a1-b[j+1].a3;
						}
						if(cha>cha2){
							swap(b[j],b[j+1]);
						}
					}
				}
				
				long long sum=0;
				for(int i=1;i<=kk[1]-w;i++){
					if(b[i].x2==2){
						sum+=b[i].a2;
					}
					if(b[i].x2==3){
						sum+=b[i].a3;
					}
				}
				for(int i=kk[1]-w+1;i<=n;i++){
					if(b[i].abc==1){
						sum+=b[i].a1;
					}
					if(b[i].abc==2){
						sum+=b[i].a2;
					}
					if(b[i].abc==3){
						sum+=b[i].a3;
					}
				}
				cout<<sum<<endl;
			}
			//1 she tuan ren duo chu;
			
			
			if(kk[2]>w){
				for(int i=1;i<=kk[2];i++){
					if(b[i].abc!=2){
						for(int j=kk[2]+1;j<=n;j++){
							if(b[j].abc==2){
								swap(b[i],b[j]);
								break;
							}
						}
					}
				}
				for(int i=1;i<=kk[2];i++){
					for(int j=1;j<kk[2];j++){
						int cha=0;
						if(b[j].x2==1){
							cha=b[j].a2-b[j].a1;
						}
						if(b[j].x2==3){
							cha=b[j].a2-b[j].a3;
						}
						int cha2=0;
						if(b[j+1].x2==1){
							cha2=b[j+1].a2-b[j+1].a1;
						}
						if(b[j].x2==3){
							cha2=b[j+1].a2-b[j+1].a3;
						}
						if(cha>cha2){
							swap(b[j],b[j+1]);
						}
					}
				}
				
				long long sum=0;
				for(int i=1;i<=kk[2]-w;i++){
					if(b[i].x2==1){
						sum+=b[i].a1;
					}
					if(b[i].x2==3){
						sum+=b[i].a3;
					}
				}
				for(int i=kk[2]-w+1;i<=n;i++){
					if(b[i].abc==1){
						sum+=b[i].a1;
					}
					if(b[i].abc==2){
						sum+=b[i].a2;
					}
					if(b[i].abc==3){
						sum+=b[i].a3;
					}
				}
				cout<<sum<<endl;
			}
			
			
			//shang mian shi 2
			
			
			if(kk[3]>w){
				for(int i=1;i<=kk[3];i++){
					if(b[i].abc!=3){
						for(int j=kk[3]+1;j<=n;j++){
							if(b[j].abc==3){
								swap(b[i],b[j]);
								break;
							}
						}
					}
				}
				for(int i=1;i<=kk[3];i++){
					for(int j=1;j<kk[3];j++){
						int cha=0;
						if(b[j].x2==1){
							cha=b[j].a3-b[j].a1;
						}
						if(b[j].x2==2){
							cha=b[j].a3-b[j].a2;
						}
						int cha2=0;
						if(b[j+1].x2==1){
							cha2=b[j+1].a3-b[j+1].a1;
						}
						if(b[j].x2==2){
							cha2=b[j+1].a3-b[j+1].a2;
						}
						if(cha>cha2){
							swap(b[j],b[j+1]);
						}
					}
				}
				
				long long sum=0;
				for(int i=1;i<=kk[3]-w;i++){
					if(b[i].x2==1){
						sum+=b[i].a1;
					}
					if(b[i].x2==2){
						sum+=b[i].a2;
					}
				}
				for(int i=kk[3]-w+1;i<=n;i++){
					if(b[i].abc==1){
						sum+=b[i].a1;
					}
					if(b[i].abc==2){
						sum+=b[i].a2;
					}
					if(b[i].abc==3){
						sum+=b[i].a3;
					}
				}
				cout<<sum<<endl;
			}
			
			
			//3 hao le
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}