#include <bits/stdc++.h>

using namespace std;
int n,m;
struct Stu{
	int xuhao;
	int people;
	} stu[105];
void my_sort(int a,int num){
	for (int i=1;i<=a;i++){
		if (stu[i].people<num){
			for (int j=a+1;j>i;j--){
				stu[j] = stu[j-1];
				}
			stu[i].people = num;
			stu[i].xuhao = a;
			break;
			}
		}
	}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	stu[0].xuhao = 1;
	for (int i=1;i<=n*m;i++){
		int temp;
		cin >> temp;
		my_sort(i,temp);
		}
	int x;
	for (x=1;x<=n*m;x++){
//		cout << stu[x].people << '>' << stu[x].xuhao << ' ';
		if (stu[x].xuhao == 1){
			break;
			}
		}
	int j = (x-1)/n+1;
	int i = (j%2==1)? (x-1)%n+1:n+1-((x-1)%n+1);
	
	cout << j << ' ' << i;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
