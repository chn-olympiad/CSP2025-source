#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][3];
int red = 0;
long long ans;

struct Node{
	int value,n;
};
//Node to1[100005],to2[100005],to3[100005];
Node to[4][100005];
bool isJoined[100005];

bool cmp(Node x,Node y){
	return x.value > y.value;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
//		cout<<"###"<<t<<endl;
		cin>>n;
//		flag = false;
		memset(isJoined,false,sizeof(isJoined));
		ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			to[1][i] = {a[i][1],i};
			to[2][i] = {a[i][2],i};
			to[3][i] = {a[i][3],i};
		} 
		sort(to[1]+1,to[1]+1+n,cmp);
		sort(to[2]+1,to[2]+1+n,cmp);
		sort(to[3]+1,to[3]+1+n,cmp);
//		for(int j = 1;j <= 3;j++){
//		for(int i = 1;i <= n;i++){
//			cout<<to[j][i].value<<'.'<<to[j][i].n<<" ";
//		}
//		cout<<endl;
//		}	
		bool flag =  to[1][1].n==to[2][1].n&&to[1][1].n==to[3][1].n;
		
//		flag = false;
		
		if(flag){
			swap(to[1][1],to[1][2]);
			swap(to[2][1],to[2][2]);
			swap(to[3][1],to[3][2]);
		}
		for(int i = 1,j = 1,k = 1,cnt = 1;;cnt++){
			if(i+j+k-3>=n){
				break;
			}
			int maxValue = -1;
			int choose = 0;
			Node t;
			if(to[1][i].value > maxValue&&i <= n/2&&!isJoined[to[1][i].n]){
				maxValue = to[1][i].value;
				choose = 1;
				t = to[1][i];
			}
			if(to[2][j].value > maxValue&&j <= n/2&&!isJoined[to[2][j].n]){
				maxValue = to[2][j].value;
				choose = 2;
				t = to[2][i];
			}
			if(to[3][k].value > maxValue &&k <= n/2&&!isJoined[to[3][k].n]){
				maxValue = to[3][k].value;
				choose = 3;
				t = to[3][i];
			}
			
			if(choose == 1){
				i++;
//				swap(to[1][1],to[1][2]);
				if(cnt == 1&&flag){
					swap(to[2][1],to[2][2]);
					swap(to[3][1],to[3][2]);
				}
			} else if(choose == 2){
				j++;
				if(cnt == 1&&flag){
					swap(to[1][1],to[1][2]);
					swap(to[3][1],to[3][2]);
				}
			} else if(choose == 3){
				k++;
				if(cnt == 1&&flag){
					swap(to[1][1],to[1][2]);
					swap(to[2][1],to[2][2]);
				}
			}
			if(maxValue == -1){
				for(int i = 1;i <= n;i++){
					if(!isJoined[i]){
						ans += max(to[1][i].value,max(to[2][i].value,to[3][i].value));
					}
				}
			}
			ans += maxValue;
			isJoined[t.n] = true;
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
