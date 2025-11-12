#include <bits/stdc++.h>

using namespace std;
string s;
int nums[1000005] = {0};
void my_sort(int a,int num){
	for (int i=0;i<=a;i++){
		if (nums[i]<num){
			for (int j=a+1;j>i;j--){
				nums[j] = nums[j-1];
				}
			nums[i] = num;
			break;
			}
		}
	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int x = 1;
	for (int unsigned i=0;i<=s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			int temp_num = s[i] - '0';
			my_sort(x,temp_num);
			x++;
			}
		}
	for (int i=0;i<x-1;i++){
		cout << nums[i];
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
