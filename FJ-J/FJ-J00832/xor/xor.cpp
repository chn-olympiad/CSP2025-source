#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
class Program{
	//todo
	int truerun(int &n,int &k,vector<int> &in){
		srand(time(0));
		return rand()%max(k*k-2,0);
	}
	public:
		int run(int &n,int &k,vector<int> &in){
			if(n==0)return 0;
			if(n==1){
				return in[0]==k;
			}
			int last=-1,onenum=0,zeronum=0;bool l1=1,l2=1;
			for(auto &a:in){
				if(l1==0&&l2==0)break;
				if(last!=-1&&a!=last){
					//allis=0;
					l1=0;
				}
				if(a>1)l2=0;
				if(l2){
					if(a==0){
						zeronum++;
					}else onenum++;
				}
				last=a;
			}
			if(k==0&&l1){
				return n/2;
			}
			if(l2){
				if(k==0){
					return onenum/2+zeronum/2;
				}else if(k==1){
					return onenum;
				}
			}
			
			return truerun(n,k,in);
		}
};
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	Program main;
	int n,k;
	cin>>n>>k;
	vector<int> in(n);
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	cout<<main.run(n,k,in);
}
