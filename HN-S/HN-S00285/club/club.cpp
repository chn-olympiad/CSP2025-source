#include<iostream>

using namespace std;

int t,num[110000][8];
int queue[110000][8],cnt[8];
bool visited[11000] = {false};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	for(int i = 0;i < t;i++){
		int n;
		cin >> n;
		for(int j = 1;j <= n;j++){
			int a1,a2,a3;
			cin >> a1 >> a2 >> a3;
			
			num[j][1] = a1; 
			num[j][2] = a2;
			num[j][3] = a3;
			if(a1 > a2 && a2 > a3){
				num[j][4] = 1;
				num[j][5] = 2;
				num[j][6] = 3;
			}
			else if(a1 > a2 && a2 < a3){
				num[j][4] = 1;
				num[j][5] = 3;
				num[j][6] = 2;
			}
			else if(a1 < a2 && a2 > a3 && a1 < a3){
				num[j][4] = 2;
				num[j][5] = 3;
				num[j][6] = 1;
			}
			else if(a1 < a2 && a2 > a3 && a1 > a3){
				num[j][4] = 2;
				num[j][5] = 1;
				num[j][6] = 3;
			}
			else if(a1 < a2 && a3 > a2){
				num[j][4] = 3;
				num[j][5] = 2;
				num[j][6] = 1;
			}
			else if(a1 > a2 && a2 > a3){
				num[j][4] = 3;
				num[j][5] = 1;
				num[j][6] = 2;
			}
		}
		int sum = 0;
		
		//还要比较每个队员对每个部门谁更满意，让更满意的进去 
		
		for(int z = 1;z <= n;z++){
			
			for(int l = 1;l <= 3;l++){
				if(num[z][4] == l && cnt[l] <= n/2-1 && !visited[z]){//第z个员工对第l个部门最满意，队列未满就入队					 
					queue[l][cnt[l]] =  num[z][num[z][4]];
					cnt[l]++;
					visited[z] = true;
					break;
				}
				else if(num[z][4] == 1 && !visited[z]){	
					if(z==n & cnt[3] == 0){
						break;
					}	
					int last = l;
					while(cnt[last] > n/2-1){//对某部门最满意但是已经满了就只能到第二满意的去
						if(last+1 < n){
							int p = num[z][l]; 
							num[z][l] = num[z][last+1];
							num[z][last+1] = p;
							last++;
						}
						else{
							break;
						}	
					}
					break;
				}
				else if(z == n){
					if(cnt[3] == 0){//至少有一个要在最后一个部门 
						queue[3][cnt[3]] =  num[z][num[z][4]];
						cnt[3] ++;
					}					
				}
			}
		} 
		//访问每个队列
		for(int r = 1;r <= n;r++){
			sum += queue[r][0] + queue[r][1] + queue[r][2];
		} 
		cout << sum << endl;
		
		int num[11000][8],queue[11000][8],cnt[8];
		bool visited[11000];
	}
	
	return 0;
} 
