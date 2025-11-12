#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[10];string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.length();i++){
		if (s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}bool flag=true;
	for(int i=9;i>0;i--){ //special case
		if (a[i]>0){
			flag=false;
			break;
		}
	}if (flag&&a[0]>0){
		printf("0");
	}else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				printf("%d",i); 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*my idea:
first, i think i can make a 1e6 array, 
and make a sort, put it out last.

but i suddenly hit a big question:
is nlogn round make TLE?

so i get another idea: like a stack, all stack save how many
number ecual theirs. I think it is right. 

It is a special case: if just have number 0, i just out "0".

maybe it's "red problem"?
*/
