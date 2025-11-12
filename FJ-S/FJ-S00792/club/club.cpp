#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	for(int j = 0;j<t;j++){
		int n;
		cin >> n;
		int a[3] = {0};
		int arr[500][3];
		int arr_[500][3];
		int arrh[500][3];
		int arrhm[500][3];
		
		for(int i = 0;i<n;i++){
			for(int l = 0;l<3;l++){
				cin >> arr[i][l];
			}
		}
		for(int i = 0;i<n;i++){//*****
			
			int maxi = 0;
			for(int l = 0;l<3;l++){
				if(arr[i][maxi]<arr[i][l])
					maxi = l;
			}
			
			int maxrd = 0;
			int time = arr[i][maxi];
			arr[i][maxi] = -1;
			
			for(int l = 0;l<3;l++){
				if(arr[i][maxrd]<arr[i][l])
					maxrd = l;
			}
			
			arr[i][maxi] = time;
			
			a[maxi]++;
			
			arr_[a[maxi]][maxi] = arr[i][maxi];
			arrh[a[maxi]][maxi] = arr[i][maxi]-arr[i][maxrd];
			arrhm[a[maxi]][maxi] = arr[i][maxrd];
			
		}
		int k;
		if(a[0]>n/2)
			k = 0;
		else if(a[1]>n/2)
			k = 1;
		else
			k = 2;
		for(int i = 1;i<=a[k];i++){
			int min = 1;
			for(int l = 2;l<=a[k];l++){
				if(arrh[min][k]>arrh[l][k]){
					min = l;
				}
			}
			swap(arr_[min][k],arr_[i][k]);
			swap(arrh[min][k],arrh[i][k]);
			swap(arrhm[min][k],arrhm[i][k]);
		}
		int m = 0;
		for(int i = n/2;i<a[k];i++){
			m += arrhm[i][k];
			a[k]--;
		}
		int max = 0;
		for(int i = 1;i<=a[0];i++)
			max += arr_[i][0];
		for(int i = 1;i<=a[1];i++)
			max += arr_[i][1];
		for(int i = 1;i<=a[2];i++)
			max += arr_[i][2];
		
		cout << max+m << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
