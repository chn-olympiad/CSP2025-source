#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int n[100005];
	cin >> a;
	int h=0, y=0, q=0;
	for(int i = 0; i < a.size(); i++){
		h++;
		if(a[i] == '1'){
			n[i] = 1;
			y++;
		}
		else if(a[i] == '2'){
			n[i] = 2;
			y++;
		}
		else if (a[i] == '3'){
			n[i] = 3;
			y++;
		}
		else if(a[i] == '4'){
			n[i] = 4;
			y++;
		}
		else if (a[i] == '5'){
			n[i] = 5;
			y++;
		}
		else if(a[i] == '6'){
			n[i] = 6;
			y++;
		}
		else if (a[i] == '7'){
			n[i] = 7;
			y++;
		}
		else if(a[i] == '8'){
			n[i] = 8;
			y++;
		}
		else if(a[i] == '9'){
			n[i] = 9;
			y++;
		}
		else if(a[i] == '0'){
			n[i] = 0;
			y++;
		}
	}
	int H[h];
	for(int i = 0; i < h; i++){
		H[i] = n[i];
	}
	sort(H+0, H+h);
	for(int j = h-1; j >= 0; j--){
		q++;
		if(q <= y){
			cout << H[j];
		}
		else{
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
