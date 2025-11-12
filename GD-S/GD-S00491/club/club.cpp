#include<bits/stdc++.h>
using namespace std;

struct Stu{
	int vol[3]={0};
	char first_vol[3] = {'*','*','*'};
	char second_vol[2] = {'*','*'};
	char third_vol = '*';
	int cha; 
};
Stu stu_1[100010];

void sort_use(Stu stu[],int n,int v,int num){
	//若第一志愿与第二志愿差值小于最小差值，则可更改调度 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n-1;j++){
			if(stu[i].cha > stu[j].cha && stu[i].first_vol[0]-'0' == v && stu[j].first_vol[0]-'0' == v){
				swap(stu[i],stu[j]);
			}
		}
	}
	for(int i=1;i<=(num - n/2);i++){
		stu[i].vol[v] = 0;
	}
}
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n,T=0;
	cin >> T;
	for(int t=1;t<=T;t++){
		long long sum = 0;
		cin >> n;
		int first_vol_1[50005]={0},first_vol_2[50005]={0},first_vol_3[50005]={0};
		int first_vol_1_num=0,first_vol_2_num=0,first_vol_3_num=0;
		int second_vol_1_num=0,second_vol_2_num=0,second_vol_3_num=0;
		int third_vol_1_num=0,third_vol_2_num=0,third_vol_3_num=0;
		for(int i=1;i<=n;i++){
			cin >> stu_1[i].vol[0] >> stu_1[i].vol[1] >> stu_1[i].vol[2];
			if(stu_1[i].vol[0] > stu_1[i].vol[1] && stu_1[i].vol[0] > stu_1[i].vol[2]){//vol_1 max 
				stu_1[i].first_vol[0] = '1';
				if(stu_1[i].vol[1] > stu_1[i].vol[2]){//vol_2 > vlo_3
					stu_1[i].second_vol[0] = '2';
					stu_1[i].third_vol = '3';
					first_vol_1_num++;
					second_vol_2_num++;
					third_vol_3_num++;
				}
				else if(stu_1[i].vol[1] < stu_1[i].vol[2]){//vol_2 < vol_3
					stu_1[i].second_vol[0] = '3';
					stu_1[i].third_vol = '2';
					first_vol_1_num++;
					second_vol_3_num++;
					third_vol_2_num++;
				}
				else{//vol_2 = vol_3
					stu_1[i].second_vol[0] = '2';
					stu_1[i].second_vol[1] = '3';
					first_vol_1_num++;
					second_vol_2_num++;
					second_vol_3_num++;
				}
			}
			else if(stu_1[i].vol[1] > stu_1[i].vol[0] && stu_1[i].vol[1] > stu_1[i].vol[2]){//vol_2 max
				stu_1[i].first_vol[0] = '2';
				if(stu_1[i].vol[0] > stu_1[i].vol[2]){//vol_1 > vol_3
					stu_1[i].second_vol[0] = '1';
					stu_1[i].third_vol = '3';
					first_vol_2_num++;
					second_vol_1_num++;
					third_vol_3_num++;
				}
				else if(stu_1[i].vol[0] < stu_1[i].vol[2]){//vol_1 < vol_3
					stu_1[i].second_vol[0] = '3';
					stu_1[i].third_vol = '1';\
					first_vol_2_num++;
					second_vol_3_num++;
					third_vol_1_num++;
				}
				else{//vol_1 = vol_3
					stu_1[i].second_vol[0] = '1';
					stu_1[i].second_vol[1] = '3';
					first_vol_2_num++;
					second_vol_1_num++;
					second_vol_3_num++;
				}
			}
			else if(stu_1[i].vol[2] > stu_1[i].vol[0] && stu_1[i].vol[2] > stu_1[i].vol[1]){//vol_3 max
				stu_1[i].first_vol[0] = '2';
				if(stu_1[i].vol[0] > stu_1[i].vol[1]){//vol_1 > vol_2
					stu_1[i].second_vol[0] = '1';
					stu_1[i].third_vol = '2';
					first_vol_3_num++;
					second_vol_1_num++;
					third_vol_2_num++;
				}
				else if(stu_1[i].vol[0] < stu_1[i].vol[1]){//vol_1 < vol_2
					stu_1[i].second_vol[0] = '2';
					stu_1[i].third_vol = '1';
					first_vol_3_num++;
					second_vol_2_num++;
					third_vol_1_num++;
				}
				else{//vol_1 = vol_2
					stu_1[i].second_vol[0] = '1';
					stu_1[i].second_vol[1] = '2';
					first_vol_3_num++;
					second_vol_1_num++;
					second_vol_2_num++;
				}
			}
			else{//vol_1 = vol_2 = vol_3
				stu_1[i].first_vol[0] = '1';
				stu_1[i].first_vol[1] = '2';
				stu_1[i].first_vol[2] = '3';
				first_vol_1_num++;
				first_vol_2_num++;
				first_vol_3_num++;
			}
			stu_1[i].cha = stu_1[i].vol[stu_1[i].first_vol[0]]-stu_1[i].vol[stu_1[i].second_vol[0]];
		}
		if(first_vol_1_num <= n/2 && first_vol_2_num <= n/2 && first_vol_3_num <= n/2){//先考虑没有社团第一志愿超过n/2的情况 
			for(int i=1;i<=n;i++){
				sum += max(stu_1[i].vol[0],max(stu_1[i].vol[1],stu_1[i].vol[2]));
			}
		}
		else{
			int num = max(first_vol_1_num,max(first_vol_2_num,first_vol_3_num));
			int v;
			if(num==first_vol_1_num) v=0;
			else if(num==first_vol_2_num) v=1;
			else if(num==first_vol_3_num) v=2;
			sort_use(stu_1,n,v,num);
			for(int i=1;i<=n;i++){
				sum += max(stu_1[i].vol[0],max(stu_1[i].vol[1],stu_1[i].vol[2]));
			}
		}
		//for(int i=1;i<=n;i++){
		//	cout << stu_1[i].vol[0] << ' ' << stu_1[i].vol[1] << ' ' << stu_1[i].vol[2] << endl;
		//}
		cout << sum << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
}
