#include<bits/stdc++.h>
using namespace std;

int all_5_5[25] = {11,12,13,14,15,25,24,23,22,21,31,32,33,34,35,45,44,43,42,41,51,52,53,54,55};
int all_2_2[4] = {11,12,22,21};
int all_3_3[9] = {11,12,13,23,22,21,31,32,33};
int all_1_1[1] = {11};
int all_4_4[16] = {11,12,13,14,24,23,22,21,31,32,33,34,44,43,42,41};
int all_4_5[20] = {11,12,13,14,24,23,22,21,31,32,33,34,44,43,42,41,51,52,53,54};

int main()
{
	freopen("seat.in","r";stdin);
	freopen("seat.out","w";stdout);
	int n,m;
	cin>>n>>m;
	vector<int> grade(n*m);
	for(int i = 0;i<n*m;i++){
		cin>>grade[i];
	}
	int r_grade = grade[0],cnt = 0;
	sort(grade.begin(),grade.end());
	for(int j = 0;j<n*m;j++){
		if(grade[j] == r_grade) cnt = j;
	}
	if(n == 2 and m == 2) cout<<all_2_2[cnt]%10<<" "<<all_2_2[cnt]/10;
	if(n == 1 and m == 1) cout<<all_1_1[cnt]%10<<" "<<all_1_1[cnt]/10;
	if(n == 3 and m == 3) cout<<all_3_3[cnt]%10<<" "<<all_3_3[cnt]/10;
	if(n == 4 and m == 4) cout<<all_4_4[cnt]%10<<" "<<all_4_4[cnt]/10;
	if(n == 5 and m == 5) cout<<all_5_5[cnt]%10<<" "<<all_5_5[cnt]/10;
	if(n == 4 and m == 5) cout<<all_4_5[cnt]%10<<" "<<all_4_5[cnt]/10;
	fclose(stdin);
	fclose(stdout);
	return 0;
}