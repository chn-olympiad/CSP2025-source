#include <fstream>
#include <algorithm>
#define maxn 1001
std::ifstream fin("seat.in");
std::ofstream fout("seat.out");
int score[maxn];
bool cmp(int left,int right){
	return left>=right;
}
int main() {
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=n*m;i++){
		fin>>score[i];
	}
	int target=score[1];
	std::sort(score+1,score+1+n*m,cmp);
	int lie=1,hang=1;
	for(int i=2;i<=n*m;i++){
		if(hang==n){
			if(lie%2==1){
				lie+=1;
			}
			else{
				hang-=1;
			}
		}
		else if(hang==1){
			if(lie%2==1){
				hang+=1;
			}
			else{
				lie+=1;
			}
		}
		else{
			if(lie%2==1){
				hang+=1;
			}
			else{
				hang-=1;
			}
		}
		if(score[i]==target){
			fout<<lie<<' '<<hang<<std::endl;
			exit(0);
		}
	}
}